#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef long long ll;

int main(void){
  int n;
  //cout << n << endl;
  while(cin >> n,n){
    int count = 0;
    int state = 0;
    rep(i,n){
      string s;
      cin >> s;
      //cout << s << endl;
      if(s == "lu"){ // +1
    	if(state == 0)
    	  state += 1;
    	else if(state == 2){
    	  state += 1;
    	  count++;
    	}else if(state == 4)
	  state = 3;
      }else if(s == "ru"){ // +2
    	if(state == 0)
    	  state += 2;
    	else if(state == 1){
    	  state += 2;
    	  count++;
    	}else if(state == 5)
	  state = 3;
      }else if(s == "ld"){
	if(state == 3)
	  state += 1;
	else if(state == 5){
	  state = 0;
	  count++;
	}else if(state == 1)
	  state = 0;
      }else if(s == "rd"){
	if(state == 3)
	  state += 2;
	else if(state == 4){
	  state = 0;
	  count ++;
	}else if(state == 2){
	  state = 0;
	}
      }
    }
  cout << count << endl;
}
}

