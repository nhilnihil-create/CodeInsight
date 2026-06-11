#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int cnt;
//---------------------------------------
void insertionSort(vector<int>& a,int g);
vector<int> shellSort(vector<int>& a);
void Show(const vector<int> a);
vector<int> GInShell(const vector<int>& a);
//---------------------------------------

int main(void)
{
	int n;
	vector<int> a;
	
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		a.push_back(num);
	}
	
	vector<int> G = shellSort(a);
	cout << G.size() << endl;  //1????????´??°m
	Show(G);  //2?????? ??´??°G[m]
	cout << cnt << endl;  //3?????? cnt
	
	for(int i = 0; i < a.size(); i++){
		cout << a[i] << endl;
	}
	
	return 0;
}

//------------------------------------------
void insertionSort(vector<int>& a,int g){
	
	for(int i = g; i < a.size(); i++){
		int v = a[i]; //?????????(g+1)?????¢????????°???
		int j = i - g;  //
		
		while(j >= 0 && a[j] > v){
			a[j+g] = a[j];
			j -= g;
			cnt++;
		}
		a[j+g] = v;
	}
}
//------------------------------------------
vector<int> shellSort(vector<int>& a){

	cnt = 0;
	vector<int> G = GInShell(a);
	int m = G.size();
	for(int i = 0; i < m; i++){
		insertionSort(a, G[i]);
	}
	return G;
}
//--------------------------------------------
void Show(const vector<int> a){
	
	for(int i = 0; i < a.size() - 1; i++){
		cout << a[i] << ' ';
	}
	cout << a[a.size() - 1] << endl;
}
//--------------------------------------------
vector<int> GInShell(const vector<int>& a){
	
	vector<int> G;
	G.push_back(1); 
	int i = 0;
	
	while(true){
		int youso = 3 * G[i] + 1;
		if(youso <= a.size()){
			G.push_back(youso);
			i++;
		}
		else{
			break;
		}
	}
	reverse(G.begin(), G.end());
	return G;
}