#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int n = 3;
    map<int, pair<int, int>> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp;
            cin>>temp;
            m[temp] = make_pair(i, j);
        }
    }
    int r[3]={0,0,0}, c[3]={0,0,0};
    int diag1 = 0, diag2 = 0;
    int s;
    cin>>s;
    int flag = 1;
    for(int i = 0; i < s; i++){
        int temp;
        cin>>temp;
        if(m.find(temp)!=m.end()){
            int row, col;
            row = m[temp].first;
            col = m[temp].second;
            r[row]++;
            if(r[row]==3){
                flag = 0;
            }
            c[col]++;
            if(c[col]==3){
                flag = 0;
            }
            if(row == col){
                diag1++;
                if(diag1 == 3){
                    flag = 0;
                }
            }
            if((row == 1 && col == 1) || (row == 0 && col == 2) || (row == 2 && col == 0)){
                diag2++;
                if(diag2 == 3){
                    flag = 0;
                }
            }
        }

    }
    if(flag)
    cout<<"No";
    else
    {
        cout<<"Yes";
    }
    
    return 0;
}