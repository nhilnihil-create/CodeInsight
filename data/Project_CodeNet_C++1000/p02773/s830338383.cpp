#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

int main() 
{
    int N;
    cin>>N;
    vector<string>S;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin>>s;
        S.push_back(s);
    }

    map<string,int>vote;
    vote.emplace(S.back(),1);
    S.pop_back();

    while (!S.empty())
    {
        auto it = vote.find(S.back());
        if(it!=vote.end())
        {
            ++(it->second);
        }
        else
        {
            vote.emplace(S.back(),1);
        }
        S.pop_back();
    }

    int vmax = 1;
    for(const auto&vt:vote)
    {
        if(vmax<vt.second)
        {
            vmax=vt.second;
        }
    }

    for(const auto&vt:vote)
    {
        if(vt.second==vmax)
        {
            cout<<vt.first<<endl;
        }
    }

}