#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        vp[i] = {x, y};
    }
    
    vector<int> perm_list(n);
    for (int i=0; i<n; i++) perm_list[i] = i;
    
    long double ans = 0;
    int divNum = 0;
    do{
        long double dist_sum = 0;
        for (int i=0; i<n-1; i++){
            int xdist = (vp[perm_list[i]].first - vp[perm_list[i+1]].first);
            int ydist = (vp[perm_list[i]].second - vp[perm_list[i+1]].second);
            dist_sum += sqrt(xdist * xdist + ydist * ydist);
        }
        divNum++;
        ans += dist_sum;
    }while(next_permutation(perm_list.begin(), perm_list.end()));
    
    cout << fixed << setprecision(10) << (long double)(ans / divNum) << endl;
}
