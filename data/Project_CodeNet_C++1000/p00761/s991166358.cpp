#include <bits/stdc++.h>

using namespace std;

vector<int> vector_compare;
int cont, valor_i, valor_j, valor_em_i;

bool encounter_occurrences(int numero) {
	vector<int>::iterator number_to_find = find(vector_compare.begin(), vector_compare.end(), numero);
	if(number_to_find != vector_compare.end()) {
		valor_j = cont;
		valor_em_i = numero;
		valor_i = distance(vector_compare.begin(), number_to_find);
		return true;
	}
	return false;
}

int max_number(int numero, int tamanho) {
	int numero_max;
	
	ostringstream convert;
	convert << numero;
	string result = convert.str();
	
	for(int index = result.size(); index < tamanho; ++ index)
		result += '0';
		
	sort(result.begin(), result.end());
	
	reverse(result.begin(), result.end());
	
	istringstream number_string(result);
	number_string >> numero_max;
	
	return numero_max;
}

int min_number(int numero, int tamanho) {
	int numero_min;
	
	ostringstream convert;
	convert << numero;
	string result = convert.str();
	
	for(int index = result.size(); index < tamanho; ++ index)
		result += '0';
		
	sort(result.begin(), result.end());
	
	istringstream number_string(result);
	number_string >> numero_min;
	
	return numero_min;
}

int compare_number(int numero, int tamanho) {
	if(encounter_occurrences(numero))
		return 0;
		
	vector_compare.push_back(numero);
	
	int numero_max = max_number(numero, tamanho);
	int numero_min = min_number(numero, tamanho);
	
	int difereca = numero_max - numero_min;
	
	cont += 1;
	
	compare_number(difereca, tamanho);
}

int main() {
	int numero, tamanho;
	
	while(true) {
		cin >> numero >> tamanho;
		
		if(numero == 0 && tamanho == 0)
			break;
			
		vector_compare.clear();
		cont = 0;
		valor_i = 0;
		valor_j = 0;
		valor_em_i = 0;
		
		compare_number(numero, tamanho);
		
		cout << valor_i << " " << valor_em_i << " " << (valor_j - valor_i) << endl;
	}
	return 0;
}
