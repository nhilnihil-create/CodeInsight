#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll i,j;
    while(true){
        ll h;
        cin >> h;
        if(h == 0){
            return 0;
        }
        vector<vector<ll>> ban(h, vector<ll>(5,0));
        for(i = h-1;i >= 0;--i){
            for(j = 0;j < 5;++j){
                cin >> ban.at(i).at(j);
            }
        }
        ll ans = 0;
        while(true){
            ll tmp_ans = ans;
            for(i = 0;i < h;++i){
                vector<pair<ll,ll>> vp;
                ll tmp = ban.at(i).at(0);
                ll num = 1;
                for(j = 1;j < 5;++j){
                    if(tmp != ban.at(i).at(j)){
                        vp.emplace_back(tmp,num);
                        tmp = ban.at(i).at(j);
                        num = 1;
                    }else{
                        ++num;
                    }
                }
                vp.emplace_back(tmp,num);
                if(vp.size() >= 4){
                    continue;
                }
                if(vp.size() == 1){
                    ans += ban.at(i).at(0)*5;
                    for(j = 0;j < 5;++j){
                        ban.at(i).at(j) = 0;
                    }
                }else if(vp.size() == 2){
                    if(vp.at(0).second >= 3){
                        ans += vp.at(0).first*vp.at(0).second;
                        for(j = 0;j < vp.at(0).second;++j){
                            ban.at(i).at(j) = 0;
                        }
                    }else if(vp.at(1).second >= 3){
                        ans += vp.at(1).first*vp.at(1).second;
                        for(j = vp.at(0).second;j < 5;++j){
                            ban.at(i).at(j) = 0;
                        }
                    }
                }else if(vp.size() == 3){
                    if(vp.at(0).second == 3){
                        ans += vp.at(0).first*vp.at(0).second;
                        for(j = 0;j < vp.at(0).second;++j){
                            ban.at(i).at(j) = 0;
                        }
                    }else if(vp.at(1).second == 3){
                        ans += vp.at(1).first*vp.at(1).second;
                        for(j = vp.at(0).second;j < vp.at(0).second + vp.at(1).second;++j){
                            ban.at(i).at(j) = 0;
                        }
                    }
                    else if(vp.at(2).second == 3){
                        ans += vp.at(2).first*vp.at(2).second;
                        for(j = vp.at(0).second + vp.at(1).second;j < 5;++j){
                            ban.at(i).at(j) = 0;
                        }
                    }
                }
            }
            if(ans == tmp_ans){
                break;
            }
            for(i = 0;i < 5;++i){
                vector<ll> tmp;
                for(j = 0;j < h;++j){
                    if(ban.at(j).at(i) != 0){
                        tmp.push_back(ban.at(j).at(i));
                    }
                }
                for(j = 0;j < tmp.size();++j){
                    ban.at(j).at(i) = tmp.at(j);
                }
                for(j = tmp.size();j < h;++j){
                    ban.at(j).at(i) = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
