#include <bits/stdc++.h>
#include <string.h>
using namespace std;


int main(){
    int N;
    vector <int> d(100000);
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>d.at(i);
    }
    sort(d.begin(),d.end()-100000+N);
    if(N%2!=0){
        cout<<0<<endl;
        return 0;
    }
    cout <<d.at(N/2)-d.at(N/2-1)<<endl;
    return 0;
}
