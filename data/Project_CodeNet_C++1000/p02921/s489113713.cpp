#include <bits/stdc++.h>
using namespace std;

int main()
{

string  S,T;
cin >> S;
cin >>T;
   
if (S==T){
cout<<3<<endl;
} 
    
else if ((S[0]==T[0] &&  S[1]!=T[1] && S[2]!=T[2]) ||
(S[0]!=T[0] && S[1]==T[1] && S[2]!=T[2] ) ||
(S[0]!=T[0] && S[1]!=T[1] && S[2]==T[2])){
cout <<1<<endl;
}
else if (S[0]!=T[0] && S[1]!=T[1] && S[2]!=T[2]){
cout <<0<<endl;
}
    
else{
cout <<2 << endl;    
}
    
}