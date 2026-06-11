#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

map<string, int> Nvotes;
vector<pair<string, int>> votes;

bool cmp(pair<string, int> &v1, pair<string, int> &v2)
{
        if(v1.second!=v2.second)return v1.second>v2.second;
        if(v1.first!=v2.first)return v1.first<v2.first;
}

void preenche()
{
    votes.reserve(Nvotes.size());
    map<string, int>::iterator i;
    for(i = Nvotes.begin(); i!=Nvotes.end(); i++)
    {
        votes.push_back(make_pair(i->first, i->second));
    }
    sort(votes.begin(), votes.end(), cmp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    string s;
    while(N--)
    {
        cin>>s;
        Nvotes.insert( make_pair(s, Nvotes[s]++) );
    }
    preenche();

    int I = 0;

    while(votes[I].second == votes[0].second)
    {
        cout<<votes[I].first<<endl;
        I++;
    }
    return 0;
}
