#include<iostream>
#include<vector>
using namespace std;
 
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(n);
    for(int i = 0; i < n; i++)
    {
        cin >> c[i];
        for(int j = 0; j < m; j++)cin >> a[i][j];
    }

    int min_cost = 12345678;

    for(int bit=1; bit < (1 << n); bit++)
    {
        int cost =0;
        vector<int> skill(m); 
        bool judge = true;

        //i 番目のbitが立っているかチェック
        for(int i =0; i<n; i++)
        {
            int mask = 1<< i;
            if(bit & mask)
            {
                //料金アップ
                cost += c[i];

                //スキルアップ
                for(int j=0; j<m; j++)
                {
                    skill[j] += a[i][j];
                }
            }
        }

        //スキルがX未満のものが一つでもあるならjudgeをfalseに
        for(int k=0; k<m; k++)
        {
            if(skill[k] < x)
            {
                judge = false;
            }
        }

        //最小費用を更新
        if(judge == true)
        {
            min_cost = min(min_cost, cost);
        }

    }

    
    if(min_cost != 12345678)
    {
        cout << min_cost;
    }
    else
    {
        cout << (-1);
    }
    
    return 0;

}
