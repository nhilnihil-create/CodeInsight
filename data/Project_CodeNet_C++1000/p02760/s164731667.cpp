#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a[3][3];
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            cin >> a[i][j];
        
    int n, x;
    cin >> n;
    for(int z=0; z<n; ++z){
        cin >> x;

        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(a[i][j] == x){
                    a[i][j] = 0;
                }
            }
        }

        for(int i=0; i<3; ++i){
            int s = 0;
            for(int j=0; j<3; ++j){
                s += a[i][j];
            }
            if(s==0){
                cout << "Yes" << endl;
                return 0;
            }
        }

        for(int i=0; i<3; ++i){
            int s = 0;
            for(int j=0; j<3; ++j){
                s += a[j][i];
            }
            if(s==0){
                cout << "Yes" << endl;
                return 0;
            }
        }

        if(a[0][0] + a[1][1] + a[2][2] == 0){
            cout << "Yes" << endl;
            return 0;
        }
        if(a[0][2] + a[1][1] + a[2][0] == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No";
    return 0;
}
