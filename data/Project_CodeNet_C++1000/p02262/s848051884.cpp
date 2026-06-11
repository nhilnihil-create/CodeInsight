#include <bits/stdc++.h>

using namespace std;


long insertionSort(vector<long>& A, int n, int g)
{
    long cnt = 0;
    for(int i = g; i < n; i++){
	int v = A.at(i);
	int j = i - g;
	while(j >= 0 && A.at(j) > v){
	    A.at(j+g) = A.at(j);
	    j = j - g;
	    cnt++;
	}
	A.at(j+g) = v;
    }
    return cnt;
}

long shellSort(vector<long>& A, int n, int m, vector<int>& G)
{
    long cnt = 0;
    for(int i = 0; i < m; i++){
	cnt += insertionSort(A, n, G.at(i));
    }
    return cnt;
}

void print(int m, vector<int>& G){
    cout << m << endl;
    string sep = "";
    for(int g: G){
	cout << sep << g;
	sep = " ";
    }
    cout << endl;
}
    
int main()
{
    int N;
    cin >> N;
    vector<long> A(N);
    for(int i = 0; i < N; i++){
	cin >> A.at(i);
    }

    int upper = ceil(pow(N, 3.0/2.0));

    vector<int> G;
    int m = 0;
    int v = 1;
    for(;;){
	if(m+1 > 100) break;
	if(v > N) break;
	m++;
	G.push_back(v);
	v = 3 * v + 1;
    }
    reverse(G.begin(), G.end());
    
    long cnt = shellSort(A, N, m, G);

    print(m, G);
    
    cout << cnt << endl;
    
    for(int a: A){
	cout << a << endl;
    }
    
    
}

