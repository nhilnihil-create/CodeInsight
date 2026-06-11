#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    if(N==1){
        cout <<"Yes"<<endl;
        return 0;
    }
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    long long stand=vec.at(0);
    
    for(int i=1;i<=N-1;i++){
        if(stand==vec.at(i)){
            continue;
        }
        if(stand<=vec.at(i)-1){
            stand =vec.at(i)-1;
            continue;
        }
        else {
            cout <<"No"<<endl;
            return 0;
        }
    }
    cout <<"Yes"<<endl;
}