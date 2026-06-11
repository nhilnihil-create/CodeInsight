// コッホ曲線
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

typedef struct st
{
    double x;
    double y;
}st_Coordinate;

void Koch_curve(st_Coordinate p1, st_Coordinate p2, int n);

int main(void)
{
    int n;
    st_Coordinate st_start, st_end;

    st_start.x = 0; st_start.y = 0;
    st_end.x = 100; st_end.y = 0;

    scanf("%d", &n);

    if( n > 0 )
    {
        // コッホ曲線の作成
        Koch_curve(st_start, st_end, n);
        // 求めた点の2重表示を防ぐため、最後の点だけ別に表示
        printf("%lf %lf\n", st_end.x, st_end.y);
    }
    else
    {
        printf("%lf %lf\n", st_start.x, st_start.y);
        printf("%lf %lf\n", st_end.x, st_end.y);
    }

    return 0;
}

// コッホ曲線を作成する関数
// p1 : 左端の点の座標
// p2 : 右端の点の座標
// count : 関数のcall回数
void Koch_curve(st_Coordinate p1, st_Coordinate p2, int n)
{
    double split_x, split_y;
    st_Coordinate s, t, u;

    if( n <= 0 )
    {
        // call回数が規定値に到達した
        return;
    }

    split_x = ( p2.x - p1.x ) / 3.0;
    split_y = ( p2.y - p1.y ) / 3.0;

    // 左端の座標
    s.x = p1.x + split_x;
    s.y = p1.y + split_y;
    // 右端の座標
    t.x = p2.x - split_x;
    t.y = p2.y - split_y;

    // 正三角形の頂点の座標 ( t を s の周りに60°だけ回転させる)
    u.x = ( cos( M_PI / 3.0 ) * ( t.x - s.x ) )
            + ( ( -1 ) * sin( M_PI / 3.0 ) * ( t.y - s.y ) ) + s.x;

    u.y = ( sin( M_PI / 3.0 ) * ( t.x - s.x ) )
            + ( cos( M_PI / 3.0 ) * ( t.y - s.y ) ) + s.y;

    // nの減算
    n--;

    if( n > 0 )
    {
        Koch_curve(p1, s, n);
        Koch_curve(s, u, n);
        Koch_curve(u, t, n);
        Koch_curve(t, p2, n);
    }
    else
    {
        // 座標の表示
        printf("%lf %lf\n", p1.x, p1.y);
        printf("%lf %lf\n", s.x, s.y);
        printf("%lf %lf\n", u.x, u.y);
        printf("%lf %lf\n", t.x, t.y);
        //printf("%lf %lf\n", p2.x, p2.y);
    }

    return;
}

