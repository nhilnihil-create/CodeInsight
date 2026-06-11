#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	
char a,b,c;
char d,e,f;
int ai,bi,ci;

cin >> a >> b >> c;
cin >> d >> e >> f;

if(a==d){
	ai=1;
}else{
	ai=0;
}

if(b==e){
	bi=1;
}else{
	bi=0;
}

if(c==f){
	ci=1;
}else{
	ci=0;
}

cout << (ai+bi+ci) << endl;
   
return 0;
}
