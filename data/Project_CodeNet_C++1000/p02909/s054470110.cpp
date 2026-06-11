#include <iostream>
#include <cmath>

using namespace std;

string s;

void solve(){
    if(s=="Sunny"){
        cout<<"Cloudy";
    }else if(s=="Cloudy"){
        cout<<"Rainy";
    }else{
        cout<<"Sunny";
    }
    cout<<"\n";
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>s){
        solve();
    }
   
   return 0;
}