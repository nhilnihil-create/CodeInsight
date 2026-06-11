#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,correct=0,pen=0;
    cin >> n >> m;
    vector<int> iscollect(n+1,0),numofwrong(n+1,0);
    for(int i=0;i<m;i++){
        int p;
        string s;
        cin >> p >> s;
        if(iscollect[p]) continue;
        if(s=="WA") numofwrong[p]++;
        if(s=="AC"){
            iscollect[p]++;
            correct++;
            pen+=numofwrong[p];
        }
    }
    cout << correct << " " << pen;
}