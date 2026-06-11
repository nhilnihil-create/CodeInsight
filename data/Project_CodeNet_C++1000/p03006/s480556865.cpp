#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int main()
{
    int N;
    cin >> N;
    vector<P> xy(N);
    for(int i=0;i<N;++i){
        cin >> xy[i].first >> xy[i].second;
    }
    sort(xy.begin(), xy.end());

    int p, q, ans=0, c;
    for(int i=0;i<N;++i){
        for(int j=i+1;j<N;++j){
            p = xy[j].first - xy[i].first;
            q = xy[j].second - xy[i].second;
            c = 0;
            for(int k=0;k<N;++k){
                for(int l=k+1;l<N;++l){
                    if(xy[l].first - xy[k].first == p && xy[l].second - xy[k].second == q){
                        ++c;
                    }
                }
            }
            ans = max(c, ans);
        }
    }

    cout << N - ans << endl;
}

