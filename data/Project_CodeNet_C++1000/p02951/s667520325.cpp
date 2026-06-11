      #include <bits/stdc++.h>

      using namespace std;
      #define           ff                first
      #define           ss                second
      #define           PF                printf
      #define           pb                push_back
      #define           odd(i)            (i & 1)
      #define           nl                printf("\n");
      #define           toDecimal(s,base) stoi(s,nullptr,base)
      #define           even(i)           (!(i & 1))
      #define           pf(x)             printf("%d",x)
      #define           iin(x)            scanf("%d",&x)
      #define           din(x)            scanf("%lf",&x)
      #define           lin(x)            scanf("%lld",&x)
      #define           pfl(x)            printf("%lld",x)
      #define           all(x)            x.begin(),x.end()
      #define           rall(x)           x.rbegin(),x.rend()
      #define           rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
      #define           DB(x)             cerr << __LINE__ << ": " << #x << " = " << (x) << endl
      #define           file_in           freopen("input.txt", "r", stdin)
      #define           file_out          freopen("output.txt", "w", stdout)
      #define           pfd(x,y)          cout << fixed << setprecision(x) << y
      #define           show(x)           for(auto it : x) cout << it << " "
      #define           showp(x)          for(auto it : x) cout << it.ss << " "
      #define           fast              ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
      #define           first_set(x)      __builtin_ffs(x)
      #define           lead_zero(x)      __builtin_clz(x)
      #define           trail_zero(x)      __builtin_ctz(x)
      #define           set_bits(x)      __builtin_popcount(x)
      #define           ERAGE(x)         x.erase(unique(all(x)),x.end())

      int main(){
            //file_in;
            //file_out;
            int tc = 1;
            //iin(tc);
            while(tc--){
                  int a,b,c;
                  iin(a);
                  iin(b);
                  iin(c);
                  a = a - b;
                  if(c >= a) cout << c - a << "\n";
                  else cout << 0 << "\n";

            }

      }
 /*****************************************************
 *   Duplicate line 	Ctr + D                       *
 *   Swap line above 	Ctr + T                       *
 *   Line cut	      Ctr + L                       *
 *   Line comment       Ctr + Shift + c               *
 *   Line delete	      Ctr + Shift + L               *
 *   move line          Alt+up/down                   *
 *****************************************************/
 /*****************************************************
 *     tie(a,b,c) = mt(1,2,3); // assign              *
 *     tie(a,b) = mt(b,a); // swap(a,b)               *
 *     tuple<int, int, int, char> t (3, 4, 5, 'g');   *
 *     int a, b;                                     *
 *     tie(b, ignore, a, ignore) = t;                *
 *****************************************************/
\
