#include<iostream>
#include<vector>

using namespace std;

int main() 
{
    int N;
    cin>>N;

    vector<int>A;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin>>a;
        A.push_back(a);
    }

    vector<int>B;
    for (int i = 0; i < N; i++)
    {
        int b;
        cin>>b;
        B.push_back(b);
    }

    vector<int>C;
    for (int i = 0; i < N-1; i++)
    {
        int c;
        cin>>c;
        C.push_back(c);
    }

    int ans=0;
    int prev=0;
    for(const auto&a:A)
    {
        ans+=B[a-1];
        if(a-prev==1)
        {
            ans+=C[a-2];
        }
        prev=a;
    }
    
    cout << ans << endl;
    return 0;   
}