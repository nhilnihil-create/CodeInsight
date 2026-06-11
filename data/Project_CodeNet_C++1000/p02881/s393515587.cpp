#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//Compiler version g++ 6.3.0

/*int main()
{
  long long tt;
  cin >> tt;
  while(tt--){
    
    int ppl,flag = 0;
    int hlp;
    cin >> ppl;
    vector <int> coinA(ppl);
    for(int i = 0; i < ppl; i++ ){
      cin >> hlp;
      coinA[i] = hlp;
    }
    map<int,int> checker;
    
    for (int i = 0; i < ppl; i++){
      
      if(i == 0){
        if(coinA[i] == 5){
          
        
        checker[5]++;
        continue;
        }
        else{
        // cout << "NO\n;";
         flag = 1;
         break;
        }
      }
      int tmp = coinA[i] - 5;
      //if(tmp == 0) continue;
      checker[coinA[i]]++;
      int an = tmp/5;
    
      
      if(checker[tmp] != 0){
        checker[tmp]--;
        
        continue;
      }
      else if(checker[5] >= an){
        checker[5] = checker[5] - an;
        continue;
      }
     
      else{
      //  cout << "NO\n";
      flag = 1;
        break;
      }
      
    }
    if(flag == 0)cout << "YES\n";
    else cout << "NO\n";
    
  }
    
}*/


int main(){
  long long N;
  cin >> N;
  long long tmp;
  long long res,ans = 1e13;
  for (int i = 1; i <= sqrt(N); i++){
    if(N % i == 0){
      tmp = N/i;
      res = (i - 1) +(tmp - 1);
      ans = min(ans,res);
    }
    
  }
  cout << ans;
  
}