#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,j,k,cnt=0;
    cin >> n;

    vector<int> L(n);
    
    for(i=0; i<n; i++){
        cin >> L.at(i) ;
    }

    sort(L.begin(),L.end());

    for(i=0; i<n-2; i++){
        for(j=i+1; j<n-1; j++){
            for(k=j+1; k<n; k++){
                int I,J,K;
                I = L.at(i);
                J = L.at(j);
                K = L.at(k);
                
                if(I+J>K && J+K>I && K+I>J && I != J && J != K && K != I){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}