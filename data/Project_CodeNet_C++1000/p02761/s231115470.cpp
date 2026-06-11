#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M; cin >> N >> M;
    int st=pow(10,N-1);
    if(st==1) st=0;
    int k=pow(10,N);
    vector<int> s(M),c(M);
    for(int i=0; i<M; i++){
        cin >> s.at(i) >> c.at(i);
    }
    int check;
    for(int i=st; i<k; i++){
        check=1;
        for(int j=0; j<M; j++){
            if(to_string(i).at(s.at(j)-1)-'0'!=c.at(j)) check=-1;
        }
        if(check==1){
            cout << i << endl;
            break;
        }
    }
    if(check==-1) cout << -1 << endl;
    
}
