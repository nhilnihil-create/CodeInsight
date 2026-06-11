#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i=0;i<n;i++) cin >> l[i];
    sort(l.begin(), l.end());
 
    int count = 0;
 
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            for(int k=0;k<j;k++) {
                if(l[i]<l[k]+l[j] && l[k]!=l[j] && l[i]!=l[j]){
                    count++;
                }
            }
        }
    }
 
    cout << count << endl;
    return 0;
}
