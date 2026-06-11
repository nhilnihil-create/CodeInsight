#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int N,A;
    cin >>N;
    vector<int> vec(N);
    vector<int> ori(N);
    for(int i=0;i<N;i++){ 
        cin >> A;
        vec[i] = A;
        ori[i] = A;
    }
 
    sort(vec.begin(),vec.end(),greater<int>());
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            if(ori[i] != vec[j]){
                cout << vec[j] << endl;
                break;
            }
            else if(ori[i] == vec[j]){
                cout << vec[j+1] << endl;
                break;
            }
        }
    }
}