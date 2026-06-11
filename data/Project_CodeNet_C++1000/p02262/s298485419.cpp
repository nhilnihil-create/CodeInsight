/**
 * shell sort
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void insertionSort(int a[], int n, int g, int & cnt)
{
  for(int i = g; i < n; ++i){
    //show
    //for(int i = 0; i<n ; ++i){ cout << a[i] <<" "; }
    // cout << endl;
    // cout << "cnt: " << cnt << endl;
    // cout << "g:   " << g << endl;
    // cout << "---" <<endl;
    
    int v = a[i];
    int j = i - g;

    while(j >= 0 && a[j] > v){
      a[j+g] = a[j];
      j = j - g;
      ++cnt;
    }
    a[j+g] = v;
  }
}


int main()
{
  const int N_max = 1000000;
  int N;
  int cnt = 0;
  int a[N_max];
  cin >> N;
  for(int i = 0; i<N ; ++i){
    cin >> a[i];
  }

  
  int k=1;
  int pow_2_k = 2;
  vector<int> G;
  while(pow_2_k - 1 <= N){
    G.push_back(pow_2_k - 1);
    ++k;
    pow_2_k *= 2;
  }

  reverse(G.begin(), G.end());
  int m = G.size();

  for(int i = 0; i < m; ++i){
    insertionSort(a, N, G[i], cnt);
  }


  //output
  //L1
  cout << m <<endl;
  //L2
  for(int i = 0; i<m ; ++i){
    cout << (i==0? "" : " ")  << G[i];
  }
  cout << endl;
  //L3
  cout << cnt << endl;
  //L4 - 
  for(int i = 0; i<N ; ++i){ cout << a[i] <<endl; }

  return 0;
}