#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int min=INT_MAX;
    for(int i=0; i<a.length(); i++){
        int co=b.length();
        for(int j=0; j<b.length(); j++){
            if(i+j>=a.length()){
                co=b.length();
                break;
            }
            if(b[j]==a[i+j]){
                co--;
            }
        }
        if(co<min)
            min=co;
    }
    cout<<min<<endl;
    return 0;
}