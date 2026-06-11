#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[100][2];
    for(int i= 0 ; i < n ; i++){
        cin >> a[i][0] >> a[i][1];
    }
    for (int i= 0; i < n-2; i++){
        if(a[i][0] == a[i][1] && a[i+1][0] == a[i+1][1] && a[i+2][0] == a[i+2][1]){
            cout << "Yes";
            return ;
        }
    }
    cout << "No";

}

int main ()
{
   solve();
   cout << "\n";
   return 0;
}
