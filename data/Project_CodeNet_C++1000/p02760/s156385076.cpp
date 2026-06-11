#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    vector<vector<int>> A(3, vector<int>(3));

    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin>>A[i][j];
        }
    }

    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;

        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(A[i][j]==n) {
                    A[i][j]=-1;
                }
            }
        }
    }

    //row check, and col check

    for(int i=0;i<3;i++) {
        if((A[i][0]==-1&&A[i][1]==-1&A[i][2]==-1)|| A[0][i]==-1&&A[1][i]==-1&&A[2][i]==-1) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    //diag check

    if((A[0][0]==-1&&A[1][1]==-1&&A[2][2]==-1)||(A[0][2]==-1&&A[1][1]==-1&&A[2][0]==-1)) {
        cout<<"Yes"<<endl;
        return 0;
    }

    cout<<"No"<<endl;



}


