#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <stack>

#define REP(i,n) for(int i=0; i<n; i++)
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;
 
#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9

using namespace std;
typedef long long ll;

int main(){
	while(1){
		string str;
		bool ok=true;
		getline(cin, str);
		//debug(str);
		if (str.length()==1 && str[0]=='.') break;
		stack<int> po;
		for (int i=0; i<str.length(); i++){
			if (str[i]=='(') po.push(0);
			else if (str[i]=='[') po.push(1);
			else if (str[i]==')'){
				if (po.size()>0 && po.top()==0){
					po.pop();
				}else{
					printf("no\n");
					ok = false;
					break;
				}
			}else if (str[i]==']'){
				if (po.size()>0 && po.top()==1){
					po.pop();
				}else{
					printf("no\n");
					ok = false;
					break;
				}
			}
		}
		
		if (ok && po.size()>0){
			printf("no\n");
			ok = false;
		}
		if (ok) printf("yes\n");
		
	}
	return 0;
}




