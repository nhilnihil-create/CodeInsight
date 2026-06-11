#include<bits/stdc++.h>
using namespace std;

int main(){
    int pote,limit;
    cin>>pote>>limit;
    vector<int>hes(pote);
    for(int i=0;i<pote;i++){
        cin>>hes.at(i);
    }
    int zahyou=0;
    int bounds=1;
    for(int i=0;i<pote;i++){
        zahyou+=hes.at(i);
        bounds++;
        if(zahyou>limit){
            bounds-=1;
            break;
            
        }
        
        
    }
    cout<<bounds<<endl;
}