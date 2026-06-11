#include<bits/stdc++.h>
using namespace std;
#define int long long 

int cnt[201010];
int cnt2[201010];

signed main(void){ 
  
  int n,k,c; cin >> n >> k >> c;
  string s; cin >> s;
  
  int pos = 0; int work = 0; int num = 0;
  
  while( pos < n && work < k ){
    
    if( s[pos] == 'o' && (num >= c  || work == 0)){
      
      work++;
      num = 0;
      cnt[pos] = work;
    }
    else{
      if(work){ num++;}
    }
    
    pos++;
  }
  
  reverse(s.begin(),s.end());
  
  pos = 0; work = 0; num = 0;
  
  while( pos < n && work < k ){
    
    if( s[pos] == 'o'  && (num >= c  || work == 0 )){ 
      num = 0;
      work++;
      cnt2[n-pos-1] = k-work+1;
    }
    else{
      if(work){num++; }
    }
    pos++;
  }
  
  for(int i = 0; i < n; i++){ 
    if( cnt[i] == cnt2[i] && cnt[i] != 0 ){ 
      cout << i+1 << endl;
    }
  }
  
  return 0;
}