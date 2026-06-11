#include <bits/stdc++.h>
using namespace std;
int main(){
int N,X;
string S,A;
cin >> N;
X=1;
vector <string> vec ;
for(int i=0;i<N;i++){
    cin >>S;
    vec.push_back(S);
    }
sort (vec.begin(),vec.end());
A=vec.at(0);
for(int j=1;j<vec.size();j++){
    if(A==vec.at(j)){
    
    }
    else{
        A=vec.at(j);
        X++;
    }
}
cout<< X<<endl;

  }