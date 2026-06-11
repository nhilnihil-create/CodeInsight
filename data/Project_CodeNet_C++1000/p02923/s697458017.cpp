#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    if(N==1){
        cout <<0 <<endl;
        return 0;
    }
    vector<int>vec(N);
    for(int i=0;i<N;i++){
        cin >>vec.at(i);
    }
    int count=0;
    vector<int>vec2;
    int a=vec.at(0);
    for(int i=1;i<N;i++){
        if(i==N-1){
            if(a>=vec.at(i)){
                count ++;
                vec2.push_back(count);
                break;
            }
            else{
                vec2.push_back(count);
                break;
            }
        }
     if(a>=vec.at(i)){
         count ++;
         a=vec.at(i);
    }
    else {
        vec2.push_back(count);
        count =0;
        a=vec.at(i);
    }
    }
    sort(vec2.begin(),vec2.end());
    reverse(vec2.begin(),vec2.end());
    cout << vec2.at(0)<<endl;
}