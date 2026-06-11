#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    bool flg = false;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] == 1) flg = true;
    }

    int count =0;
    int num=1;
    int pre_ids=0;
    if(flg){
        for(int i=0; i<n; i++){
            if(a[i] == num)
                num++;
            else
                count++;
        }
    }
    
    if(flg) cout << count << endl;
    else    cout << "-1"<< endl;

    return 0;

}