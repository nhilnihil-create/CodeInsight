#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

vector<ll> workable_earliest(string S,ll C, ll K)
{
    ll ssize = S.size();
    
    vector<ll> answers;
    for(int i=0;i<ssize;i++)
    {
        if(S[i]=='o')
        {
            answers.push_back(i);
            break;
        }
    }
    
    for(int i=answers[0]+C+1;i<ssize && answers.size() < K;)
    {
        if(S[i]=='o')
        {
            answers.push_back(i);
            i+=C+1;
        }
        else
        {
            i++;
        }
    }

    for(auto& x : answers)
    {
        x++;
    }

    return answers;
}

vector<ll> workable_latest(string S, ll C, ll K)
{
    ll ssize = S.size();

    vector<ll> answers;

    for(int i=ssize-1;i>=0;i--)
    {
        if(S[i]=='o')
        {
            answers.push_back(i);
            break;
        }
    }

    for(int i=answers[0]-C-1;i>=0 && answers.size() < K;)
    {
        if(S[i]=='o')
        {
            answers.push_back(i);
            i-=(C+1);
        }
        else
        {
            i--;
        }
    }

    ll anssize = answers.size();

    vector<ll> copy(anssize);
    for(int i=0;i<anssize;i++)
    {
        copy[i] = answers[anssize-i-1] + 1;
    }

    return copy;
}

int main()
{
    ll N,K,C;
    cin >> N >> K >> C;

    string S;
    cin >> S;

    vector<ll> ans_earliest = workable_earliest(S,C,K);
    vector<ll> ans_latest = workable_latest(S,C,K);

/*    for(int i=0;i<K;i++)
    {
        ans_earliest[i]++;
        ans_latest[i]++;
    }*/

    vector<ll> answers;

    for(int i=0;i<K;i++)
    {
        if(ans_earliest[i]==ans_latest[i]) answers.push_back(ans_latest[i]);
    }

    for(auto x : answers)
    {
        cout << x << endl;
    }
    return 0;
}