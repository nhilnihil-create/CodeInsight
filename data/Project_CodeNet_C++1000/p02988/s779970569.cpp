#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> vec(N);
    for(int i=0;i<N;i++){
        cin>>vec.at(i);
    }
    int count=0;
    for(int i=0;i<N-2;i++){
        if(vec.at(i)<vec.at(i+1)&&vec.at(i+1)<vec.at(i+2)||vec.at(i)>vec.at(i+1)&&vec.at(i+1)>vec.at(i+2)){
            count++;
        }
    }
    cout<<count<<endl;
}
