#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

#define INF 0x3f3f3f3f
#define eps 1e-5

typedef long long LL;
const double pi = acos(-1.0);
const long long mod = 25 * 1E8;
using namespace std;

int a[1000005];
LL cnt;
int l;
int N;
vector<int> G;

void insertionSort(int g,int N)
{
    for(int i = g;i < N;i++)
    {
        int v = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > v)
        {
            a[j + g] = a[j];
            j -= g;
            cnt++;
        }
        a[j + g] = v;
    }
}

void shellSort(int N)
{
    int h = 1;
    while(1)
    {
        //if(h > N)
            //break;
        //printf("h = %d,N = %d\n",h,N);
        G.push_back(h);
        h = 3 * h + 1;
        if(h > N)
            break;
    }
    for(int i = G.size() - 1;i >= 0;i--)
        insertionSort(G[i],N);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N;
    cin >> N;
    //printf("N = %d\n",N);
    for(int i = 0;i < N;i++)
        cin >> a[i];
    cnt = 0;
    shellSort(N);
    cout << G.size() << endl;
    for(int i = G.size() - 1;i > 0;i--)
        printf("%d ",G[i]);
    printf("%d\n",G[0]);
    printf("%d\n",cnt);
    for(int i = 0;i < N;i++)
        printf("%d\n",a[i]);
    return 0;
}