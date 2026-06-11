#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,k,q;	cin >> n >> k >> q;
  vector<int>	score(n,k-q);
  
  for(int i=0;i<q;i++){
    int num;	cin >> num;	num--;
    score[num]++;
  }
  
  for(int i=0;i<n;i++){
    if(score[i]<=0)	cout << "No" << endl;
    else cout << "Yes" << endl;
  } 
}