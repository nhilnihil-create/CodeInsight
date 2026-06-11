        #include<bits/stdc++.h>
        #define ll long long
        #define rep(i,a,b) for(int i=a;i<=b;i++)
        using namespace std;
        const int maxn=400010;
        const double pi=acos(-1.0);
        struct point{
            int x,y;
            double angle;
        };
        bool cmp(point w,point v){ return w.angle<v.angle; }
        point a[maxn]; ll ans,x,y;
        void update(){ ans=max(ans,1LL*x*x+y*y); }
        int main()
        {
            int N,head=0;
            scanf("%d",&N);
            rep(i,1,N){
                scanf("%d%d",&a[i].x,&a[i].y);
                a[i].angle=atan2(a[i].y,a[i].x);
            }
            sort(a+1,a+N+1,cmp);
            rep(i,1,N){
                a[i+N]=a[i];
                a[i+N].angle=a[i].angle+pi*2;
            }
            rep(i,1,N){
                x-=a[i-1].x; y-=a[i-1].y;
                update();
                while(head+1-i+1<=N&&head+1<=N+N&&a[head+1].angle-a[i].angle<=pi){
                    head++; x+=a[head].x; y+=a[head].y;
                    update();
                }
            }
            printf("%.12lf\n",sqrt(ans));
            return 0;
        }