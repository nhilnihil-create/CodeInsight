#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int N;
    float v;
    cin >> N;
    vector<float> vec{};
    for(int i=0;i<N;i++){
        cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    float a,b;
    
    while(1){
        a = vec[0];
        b = vec[1];
        vec.erase(vec.begin());
        vec.erase(vec.begin());
        vec.push_back((a+b)/2);
        sort(vec.begin(), vec.end());
        if(vec.size() == 1) break;
    }
    
    cout << vec[0] << endl;
}