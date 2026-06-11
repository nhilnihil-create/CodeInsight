#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
    }
    if(N%2==1||N==0){
        cout << 0 <<endl;
    }
    else{
        sort(vec.begin(),vec.end());
        if(vec.at(N/2-1)==vec.at(N/2)){
            cout << 0 << endl;
        }
        else{
            cout <<vec.at(N/2)-vec.at(N/2-1)<<endl;
        }

    }
}