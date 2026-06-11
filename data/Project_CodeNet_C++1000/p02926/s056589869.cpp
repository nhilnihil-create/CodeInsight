#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main()
{
    std::cout << std::setprecision(20);
    
    int N;cin >> N;
    vector<pair<double, pair<int, int>>> vec;
    for(int i = 0;i < N;i++){
        int b,c;cin >> b >> c;
        if(b == 0 && c == 0)vec.push_back(make_pair(0, make_pair(b, c)));
        else vec.push_back(make_pair(atan2(c, b), make_pair(b, c)));
    }
    //cout<<"Uku"<<endl;
    sort(vec.begin(), vec.end());
    vector<pair<LL, LL>> ruiseki;
    ruiseki.push_back({0, 0});
    for(int i = 0;i < vec.size();i++){
        ruiseki.push_back({ruiseki.back().first + vec.at(i).second.first, ruiseki.back().second + vec.at(i).second.second});
    }
    for(int i = 0;i < vec.size();i++){
        ruiseki.push_back({ruiseki.back().first + vec.at(i).second.first, ruiseki.back().second + vec.at(i).second.second});
    }

    LL ans = 0;
    for(int i = 0;i < ruiseki.size()-1;i++){
        for(int j = i+1;j < ruiseki.size();j++){
            if(j - i > N)break;
         //   cout<<i<<" "<<j<<endl;
            LL x = ruiseki.at(j).first - ruiseki.at(i).first;
            LL y = ruiseki.at(j).second - ruiseki.at(i).second;
            //cout<<i<<" "<<j<<endl;
            ans = max(ans, (LL)pow(x, 2) + (LL)pow(y, 2));
        }
    }
    cout<<sqrt(ans)<<endl;
    return 0;
}
