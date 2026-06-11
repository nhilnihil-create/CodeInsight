#include<iostream>
#include<vector>

using namespace std;

int main() 
{
    int N,K;
    cin >>N;
    cin >>K;

    vector<bool> okasi(N,false);

    for(int j=0;j<K;++j)
    {
        int d;
        cin >>d;
        for(int i=0;i<d;++i)
        {
            int kasi;
            cin >>kasi;
            if(okasi[kasi-1]==false)
            {
                okasi[kasi-1]=true;
            }
        }
    }

    int itazura=0;
    for(auto o:okasi)
    {
        if(!o)
        {
            ++itazura;
        }
    }

    cout << itazura <<endl;
    return 0;
}
