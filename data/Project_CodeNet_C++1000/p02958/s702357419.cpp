#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N,cnt=0,m=0;
    vector <int> entered;
    vector <int> required;
    cin >>N;
    for(int i=0;i<N;i++){
        cin>>m;
        entered.push_back(m);
    }
    for(int i=1;i<N+1;i++){
        required.push_back(i);
    }
    for(int i=0;i<N;i++){
        if(entered[i] != required[i]){
            cnt++;
        }
    }
    if(cnt>2){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    return 0;
}