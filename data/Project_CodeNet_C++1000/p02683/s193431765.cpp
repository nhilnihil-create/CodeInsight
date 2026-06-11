#include <iostream>
#include <vector>

const int INF = 1001001001;

int main(){
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<int> c(n);
    std::vector<std::vector<int>> a(n, std::vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
        for (int j = 0; j < m; j++)
        {
            std::cin >> a[i][j];
        }
    }

    int min_cost = INF; //大きな数で初期化
    for (int i = 0; i < 1 << n; i++) //買う・買わないの組み合わせを二進数で列挙（pow(2, n)通り）
    {
        int cost = 0; //金額
        std::vector<int> skill(m);
        for (int j = 0; j < n; j++) //それぞれの本について買うか買わないかチェック
        {
            if (i >> j & 1) //二進数i(ex. 110)の左からj桁目(=初めからj番目の本)が1(=買う)のとき
            {
                cost += c[j]; //j番目の本の金額を足す
                for (int k = 0; k < m; k++) /* 今回の本のチョイスのとき、m種類全てのアルゴリズムについて得られるskillを計算 */
                {
                    skill[k] += a[j][k]; //skill[k]にj番目の本で得られるk個目のアルゴリズムのskill(a[j][k])を足す
                }
            }    
        }
        /* 後はm種類のアルゴリズムのskillがxを超えているかチェック */
        bool over = true;
        for (int k = 0; k < m; k++) 
        {
            if (skill[k] < x) //k番目のアルゴリズムのskillがxを超えていなかったとき
            {
                over = false;
            }
        }
        if(over) //overがtrueのままのとき
        {
            min_cost = std::min(min_cost, cost); //min_costより少ないcostが見つかったら置き換える
        }
    }
    if (min_cost == INF) //min_costがINFのままのとき（条件を満たす本の選び方が見つからなかったとき）
    {
        std::cout << -1 << std::endl;
    }
    else //条件を満たす本の選び方が見つかったとき
    {
        std::cout << min_cost << std::endl;
    }
    
    return 0;
}