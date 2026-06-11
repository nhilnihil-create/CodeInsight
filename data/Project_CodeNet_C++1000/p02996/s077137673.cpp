#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<tuple<int,int>> ab(n);
    int a,b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        ab.at(i)=make_tuple(b,a);
    }

    sort(ab.begin(),ab.end());

    int time=0;
    string ans="Yes";
    for(int i=0; i<n; i++){
        time+=get<1>(ab.at(i));
        if(time>get<0>(ab.at(i))){
            ans="No";
            break;
        }
        //cout << time << endl;
    }
    cout << ans << endl;
}