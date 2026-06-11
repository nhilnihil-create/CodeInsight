#include <iostream>
#include <vector>

using namespace std;
int main() {
    
    int n,a,x,y;
    cin >> n;

    vector<vector<pair<int,int> > > v(n);

    for(int i=0;i<n;i++){
        cin >> a;
        for(int j=0;j<a;j++) {
            cin >> x >> y;
            v[i].push_back(make_pair(x,y));
        }
    }

    /*for(int i=0;i<n;i++){
        cout << i << endl;
        for(int j=0;j<v[i].size();j++) {
            cout << v[i][j].first << " " << v[i][j].second << endl;
    
        }
    }
    */
    int ans = 0;
    bool s[n];
    for(int i=0;i<(1<<n);i++) {
        bool status = true;
        int t=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                t+=1;
                s[j] = true;
            } else {
                s[j] = false;
            }
        }

        for(int j=0;j<n;j++) {
            for(int k=0;k<v[j].size();k++) {

                if(s[j]) {

                    if(v[j][k].second==1) {
                        if(s[v[j][k].first-1] == false) status = false;
                    } else {
                        if(s[v[j][k].first-1] ==  true) status = false;
                    }


                } 
            }
        }
        if(status) ans = max(ans, t);
    }
    cout <<ans <<endl;
}
