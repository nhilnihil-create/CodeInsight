#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    vector<int>vec(N);
    vector<int>vec2(N);
    for(int i=0;i<N;i++){
        cin >> vec.at(i);
       vec2.at(i)=vec.at(i);
    }
    sort(vec2.begin(),vec2.end());
    reverse(vec2.begin(),vec2.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(vec.at(i)==vec2.at(j)){
                if(vec2.at(j)==vec2.at(j+1)){
            cout <<vec2.at(j)<<endl;
            break;                    
                }
            }
            if(vec.at(i)!=vec2.at(j)){
            cout <<vec2.at(j)<<endl;
            break;
            }
            
        }
    }

}