#include<bits/stdc++.h>
using namespace std ;

int main() {
  string S ; 
  cin >> S ; 
  int Q ; 
  cin >> Q ; 
  deque<char> q ; 
  
  for(char c : S) q.push_back(c) ; 
  
  int A = 1 ; 
  for(int i = 0 ; i < Q ; i++){
    int T ;  cin >> T ;  
    if(T == 1){
      A = (A + 1)%2 ;
    }
    if(T != 1){
      int F ; cin >> F ; 
      
      if(F == 1){
        if(A == 1){
        	char C ; 
        	cin >> C ;
        	q.push_front(C) ; 
        }
        else{
            char C ; 
            cin >> C ;
            q.push_back(C) ; 
        }
      }
      else{
        if(A == 1){
        	char C ; 
        	cin >> C ;
            q.push_back(C) ; 
        }
        else{
            char C ; 
            cin >> C ;
            q.push_front(C) ; 
        }         
      }
    }
  }
  
  if(A == 0){
    reverse(q.begin(),q.end());
  }

  string ans ; 
  for(char c : q) ans += c ; 
  cout << ans << endl;
  

  
}