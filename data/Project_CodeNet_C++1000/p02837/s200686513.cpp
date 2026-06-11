#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N, -1));
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int x,y;
            cin >> x >> y;
            A.at(i).at(x-1) = y;
        }
    }
    int ans=0;

    for(int bit=0; bit<(1<<N); bit++){
        vector<int> P(N, 0);
        for(int i=0; i<N; i++){
            if(bit & (1<<i)){
                P.at(i) = 1;
            }
        }
        bool ok=true;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(P.at(i) == 1){
                    if(A.at(i).at(j)==0 && P.at(j)==1){
                        ok = false;
                    }
                    if(A.at(i).at(j)==1 && P.at(j)==0){
                        ok = false;
                    }

                }
            }
        }
        if(ok){
            int n=0;
            for(int i=0; i<N; i++){
                n += P.at(i);
            }
            ans = max(n, ans);
        }
    }
    cout << ans << endl;
}