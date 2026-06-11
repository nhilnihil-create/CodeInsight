# include <iostream>
# include <algorithm>
# include <vector>
# include <map>
using namespace std;

int n;
int a[100005];
bool allzero=true;; //all 0s//
map <int, int> mint;
vector < pair<int, int> > vpair;

bool sortpairs(pair <int, int> a, pair <int, int> b)
{
    if (a.first<b.first)
    {
        return true;
    }

    return false;
}

int main()
{
    cin>>n;

    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        if (a[i]!=0)
        {
            allzero=false;
        }
    }

    if (allzero)
    {
        cout<<"Yes"<<endl;
        return 0;
    }

    for (int i=1; i<=n; i++)
    {
        mint[a[i]]++;
    }

    for (auto keyvalue : mint)
    {
        vpair.push_back(make_pair(keyvalue.first, keyvalue.second));
    }

    sort(vpair.begin(), vpair.end(), sortpairs);

    if (vpair.size()==2)
    {
        if (vpair[0].second==n/3 && vpair[1].second==2*n/3) //vpair[0] is expected to be 0//
        {
            cout<<"Yes"<<endl;
            return 0;
        }
    }

    if (vpair.size()==3)
    {
        if (vpair[0].second==n/3 && vpair[1].second==n/3 && vpair[2].second==n/3)
        {
            if ((vpair[0].first^vpair[1].first^vpair[2].first)==0)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;
}