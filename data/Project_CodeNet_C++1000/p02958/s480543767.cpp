#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, temp,cnt = 0;
    cin >> n;
    vector<int> vec,vec2;
    for(int i= 0; i < n ; ++i){
        cin >> temp;
        vec.push_back(temp);
    }
    vec2 = vec;
    sort(vec.begin(), vec.end());
    for(int j = 0; j < n; ++j){
        if(vec[j]!=vec2[j]){
            ++cnt;
        }
    }
    if(cnt==2 || cnt == 0){
        cout<< "YES";
    }
    else
    {
        cout<< "NO";
    }
    
}