#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int n, m;
        cin >> n >> m;
        if(n == 0){
            break;
        }
        
        vector< pair<int, int> > pd(n);
        for(int i=0; i<n; i++){
            cin >> pd[i].second >> pd[i].first;
        }
        sort(pd.begin(), pd.end(), greater< pair<int, int> >());
        
        for(int i=0; i<pd.size(); i++){
            if(m <= pd[i].second){
                pd[i].second -= m;
                break;
            }else{
                m -= pd[i].second;
                pd[i].second = 0;
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += pd[i].first * pd[i].second;
        }
        cout << ans << endl;
    }
  
    return 0;
}