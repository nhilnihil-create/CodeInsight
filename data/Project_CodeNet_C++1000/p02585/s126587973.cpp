#include <algorithm>　　　 //STL 通用算法
#include <bitset>　　　　　//STL 位集容器
#include <cctype>         //字符处理
#include <cerrno> 　　　　 //定义错误码
#include <cfloat>　　　　 //浮点数处理
#include <ciso646>         //对应各种运算符的宏
#include <climits> 　　　　//定义各种数据类型最值的常量
#include <clocale> 　　　　//定义本地化函数
#include <cmath> 　　　　　//定义数学函数
#include <complex>　　　　 //复数类
#include <csignal>         //信号机制支持
#include <csetjmp>         //异常处理支持
#include <cstdarg>         //不定参数列表支持
#include <cstddef>         //常用常量
#include <cstdio> 　　　　 //定义输入／输出函数
#include <cstdlib> 　　　　//定义杂项函数及内存分配函数
#include <cstring> 　　　　//字符串处理
#include <ctime> 　　　　　//定义关于时间的函数
#include <cwchar> 　　　　 //宽字符处理及输入／输出
#include <cwctype> 　　　　//宽字符分类
#include <deque>　　　　　 //STL 双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream> 　　　 //文件输入／输出
#include <functional>　　　//STL 定义运算函数（代替运算符）
#include <limits> 　　　　 //定义各种数据类型最值常量
#include <list>　　　　　　//STL 线性列表容器
#include <locale>         //本地化特定信息
#include <map>　　　　　　 //STL 映射容器
#include <memory>         //STL通过分配器进行的内存分配
#include<new>            //动态内存分配
#include <numeric>         //STL常用的数字操作
#include <iomanip> 　　　 //参数化输入／输出
#include <ios>　　　　　　 //基本输入／输出支持
#include <iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream> 　　　//数据流输入／输出
#include <istream>　　　　 //基本输入流
#include <iterator>        //STL迭代器
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL 队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　 //基于字符串的流
#include <stack>　　　　　 //STL 堆栈容器
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　 //底层输入／输出支持
#include <string>　　　　　//字符串类
#include <typeinfo>        //运行期间类型信息
#include <utility>　　　　 //STL 通用模板类
#include <valarray>        //对包含值的数组的操作
#include <vector>　　　　　//STL 动态数组容器
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    ll n,k;cin >>n>>k;
    vector<ll>p(n);vector<ll>c(n);
    for (int i = 0; i < n; ++i){
        cin >>p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i)cin >>c[i];
    vector<bool>used(n,false);
    vector<vector<ll>>ss;
    ll ans=-INFll;
    for (int i = 0; i < n; ++i) {
        if(used[i])continue;
        vector<ll>s;
        int now=i;
        while(!used[now]){
            s.push_back(c[now]);
            used[now]=true;
            now=p[now];
        }
        ss.push_back(s);
    }
    for(auto v:ss){
        ll loop=v.size();
        vector<ll>sum(2*loop+1,0);
        for (int i = 0; i <loop*2; ++i)sum[i+1]=sum[i]+v[i%loop];
        vector<ll>mx(loop,-INFll);
        for (int i = 0; i < loop; ++i) {
            for (int j = 0; j < loop; ++j) {
                mx[j]=max(mx[j],sum[i+j]-sum[i]);
            }
        }
//        for (int i = 0; i < loop; ++i) {
//            cout<<i<<" "<<mx[i]<<" ";
//        }
//        cout <<endl;
        for (int r = 0; r <loop; ++r) {
            if(r>k)continue;
            ll q=(k-r)/loop;
            if(r==0&&q==0)continue;
            if(sum[loop]>0)ans=max(ans,mx[r]+sum[loop]*q);
            else if(r>0)ans=max(ans,mx[r]);
        }
    }
    cout <<ans <<endl;
}
