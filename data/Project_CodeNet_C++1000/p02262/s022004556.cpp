#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

int cnt;

void print_vector(vector<int> &num)
{
	for(int i = 0; i < num.size(); i++){
		if(i == 0){
			cout << num[i];
		}
		else{
			cout << " " << num[i];
		}
	}
	cout << endl;
}
void insertionSort(vector<int> &num, int g)
{
	for(int i = g; i <= num.size() - 1; i++){
		int v = num[i];
		int j = i - g;
		while(j >= 0 && num[j] > v){
			num[j + g] = num[j];
			j = j - g;
			cnt++;
		}
		num[j + g] = v;
	}
}
vector<int> makeG(int n)
{
	vector<int> G;
	int g = 1;
	while(g <= n){
		G.push_back(g);
		g = 3 * g + 1; 
	}
	reverse(G.begin(), G.end());
	
	return G;
}
vector<int> shellSort(vector<int> &num)
{
	cnt = 0;
	vector<int> G = makeG(num.size());
	for(int i = 0; i < G.size(); i++){
		insertionSort(num, G[i]);
	}
	return G;
}
int main(void)
{	
	int n;//??°????????????
	cin >> n;
	
	vector<int> num(n);
	
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	vector<int> G = shellSort(num);
	
	cout << G.size() << endl;
	print_vector(G);
	cout << cnt << endl;
	
	shellSort(num);
	for(int i = 0; i < num.size(); i++){
		cout << num[i] << endl;
	}
	
	return 0;
}