#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int n;
int m;
vector<int> ve;
multiset<int> se;

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    m = (1 << n);
    for(int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        se.insert(t);
    }
    auto it = se.end();
    it--;
    ve.push_back(*it);
    se.erase(it);
    for(int i = 1; i < m; i += i)
    {
        for(int j = ve.size() - 1; j >= 0; j--)
        {
            auto it2 = se.lower_bound(ve[j]);
            if(it2 == se.end() || *it2 >= ve[j] && it2 != se.begin()) it2--;
            else if(*it2 >= ve[j])
            {
                printf("No");
                return 0;
            }
            ve.push_back(*it2);
            se.erase(it2);
        }
    }
    printf("Yes");
    return 0;
}
