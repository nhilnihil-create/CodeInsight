#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m;
    cin >> n >> m;
    vector<bool> problem(n,false);
    vector<int> penalty(n,0);
    int AC=0,WA=0;

    int p;
    string s;
    for(int i=0; i<m; i++){
        cin >> p >> s;
        if(!problem.at(p-1)){
            if(s=="AC"){
                problem.at(p-1)=true;
                AC++;
            }
            if(s=="WA"){
                penalty.at(p-1)++;
            }
        }
        //cout << AC << ' ' << WA << endl;
    }
    for(int i=0; i<n; i++){
        if(problem.at(i)) WA+=penalty.at(i);
    }

    cout << AC << ' ' << WA << endl;
}