#include<iostream>
#include<string>
#include<cmath>
#include<array>
#include<vector>
#include<numeric>

using ll = long long;
using std::cin;
using std::cout;
using std::endl;


int main(){
    ll N;
    cin>>N;
    cout.precision(20);
    std::vector<ll> xs,ys;
    ll rN=0;
    for(ll i=0;i<N;++i){
        ll x,y;
        cin>>x>>y;
        if(x!=0 || y!=0){
            xs.push_back(x);
            ys.push_back(y);
            rN++;
        }
    }
    N=rN;
    ll centx=std::accumulate(xs.begin(),xs.end(),0ll);
    ll centy=std::accumulate(ys.begin(),ys.end(),0ll);

    std::vector<ll> sxs,sys;
    auto calcn=[](ll dx,ll dy,ll x,ll y)->ll{
        // cout<<dx<<" "<<dy<<" "<<x<<" "<<y<<endl;
        return -x*dy+y*dx;
    };
    auto calcp=[](ll dx,ll dy,ll x,ll y)->ll{
        return x*dx+y*dy;
    };
    double ans;
    if(N==0){
    }else if(N==1){
        sxs.push_back(xs.at(0));
        sxs.push_back(-xs.at(0));
        sys.push_back(ys.at(0));
        sys.push_back(-ys.at(0));
    }else{
        ll x0=xs.at(0);
        ll y0=ys.at(0);
        ll ind=-1;
        for(ll i=1;i<N;++i){
            ll xi=xs.at(i);
            ll yi=ys.at(i);
            if(xi*y0-yi*x0!=0){
                ind=i;
                break;
            }
        }
        if(ind==-1){
            if(x0!=0){
                ll sabsx=0;
                for(auto& x:xs){
                    sabsx+=std::abs(x);
                }
                ll po=centx>0?centx+sabsx:centx-sabsx;
                ans=std::abs(static_cast<double>(po)*std::sqrt(x0*x0+y0*y0)/x0/2);
            }else{
                ll sabsy=0;
                for(auto& y:ys){
                    sabsy+=std::abs(y);
                }
                ll po=centy>0?centy+sabsy:centy-sabsy;
                ans=std::abs(static_cast<double>(po)*std::sqrt(x0*x0+y0*y0)/y0/2);
            }
            cout<<ans<<endl;
            return 0;
        }

        ll x1=xs.at(ind);
        ll y1=ys.at(ind);
        xs.erase(xs.begin());
        xs.erase(xs.begin()+ind-1);
        ys.erase(ys.begin());
        ys.erase(ys.begin()+ind-1);
        ll pro=x0*y1-x1*y0;
        if(pro>0){
            sxs.push_back(x0+x1);
            sxs.push_back(-x0+x1);
            sxs.push_back(-x0-x1);
            sxs.push_back(x0-x1);
            sys.push_back(y0+y1);
            sys.push_back(-y0+y1);
            sys.push_back(-y0-y1);
            sys.push_back(y0-y1);
        }else{
            sxs.push_back(x1+x0);
            sxs.push_back(-x1+x0);
            sxs.push_back(-x1-x0);
            sxs.push_back(x1-x0);
            sys.push_back(y1+y0);
            sys.push_back(-y1+y0);
            sys.push_back(-y1-y0);
            sys.push_back(y1-y0);
        }
    }
    // for (auto i = xs.begin(); i != xs.end(); ++i)cout << *i << ' ';
    //     cout<<endl;
    for(ll i=0;i<N-2;++i){
        // for (auto i = sxs.begin(); i != sxs.end(); ++i)cout << *i << ' ';
        // cout<<endl;
        // for (auto i = sys.begin(); i != sys.end(); ++i)cout << *i << ' ';
        // cout<<endl;
        ll x=xs.at(i);
        ll y=ys.at(i);
        std::vector<ll> nsxs,nsys;
        ll siz=sxs.size();
        for(ll j=0;j<siz;++j){
            ll jm=j==0?siz-1:j-1;
            ll jp=j==siz-1?0:j+1;
            ll nj=calcn(x,y,sxs.at(j),sys.at(j));
            ll njm=calcn(x,y,sxs.at(jm),sys.at(jm));
            ll njp=calcn(x,y,sxs.at(jp),sys.at(jp));
            if(nj>njm && nj>njp){
                nsxs.push_back(sxs.at(j)+x);
                nsys.push_back(sys.at(j)+y);
                nsxs.push_back(sxs.at(j)-x);
                nsys.push_back(sys.at(j)-y);
            }else if(nj<njm && nj<njp){
                nsxs.push_back(sxs.at(j)-x);
                nsys.push_back(sys.at(j)-y);
                nsxs.push_back(sxs.at(j)+x);
                nsys.push_back(sys.at(j)+y);
            }else if(nj>njm || nj<njp){
                nsxs.push_back(sxs.at(j)+x);
                nsys.push_back(sys.at(j)+y);
            }else if(nj<njm || nj>njp){
                nsxs.push_back(sxs.at(j)-x);
                nsys.push_back(sys.at(j)-y);
            }
        }
        sxs=nsxs;
        sys=nsys;
    }
    // for (auto i = sxs.begin(); i != sxs.end(); ++i)cout << *i << ' ';
    //     cout<<endl;
    // for (auto i = sys.begin(); i != sys.end(); ++i)cout << *i << ' ';
    //     cout<<endl;
    auto itx=sxs.begin();
    auto ity=sys.begin();
    ll max=0;
    for(;itx!=sxs.end();itx++,ity++){
        ll sx=*itx+centx;
        ll sy=*ity+centy;
        ll sqn=sx*sx+sy*sy;
        if(sqn>max){
            max=sqn;
        }
    }
    ans=std::sqrt(static_cast<double>(max)/4);
    cout<<ans<<endl;
}