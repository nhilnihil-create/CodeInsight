#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

vector<int> P = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443};

class Box
{
    public:
    int number;
    int number_of_balls;
    vector<int> divs;
};

void Div(int N, Box boxes[])
{
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j+=(i+1))
        {
            boxes[j].divs.push_back(i);
        }
    }
}

void BallCounter(int N, Box boxes[], vector<int>& ballCounter)
{
    for(int i=N-1;i>=0;i--)
    {
        if(boxes[i].number_of_balls==1)
        {
            ballCounter[i]=1;
            for(auto x : boxes[i].divs)
            {
                boxes[x].number_of_balls++;
                boxes[x].number_of_balls%=2;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    Box boxes[N];
    for(int i=0;i<N;i++)
    {
        boxes[i].number = i+1;
        cin >> boxes[i].number_of_balls;
    }

    Div(N,boxes);

    vector<int> ballCounter(N,0);

    BallCounter(N,boxes,ballCounter);

    vector<int> ans;

    for(int i=0;i<N;i++)
    {
        if(ballCounter[i]==1)
        ans.push_back(i+1);
    }

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i];
        if(i!=ans.size()-1)
        {
            cout << ' ';
        }
    }
    if(ans.size()!=0)
    cout << endl;

    return 0;
}