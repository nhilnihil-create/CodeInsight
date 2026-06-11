#include <iostream>
#include <vector>

unsigned gaps[] = {1,8,23,77,281,1073,4193,16577,65921,262913};
// generated from pow(4,i)+3*pow(2,i-1)+1 (prefixed with 1)

unsigned insertion_sort(unsigned a[], unsigned n, unsigned gap = 1){
  unsigned count = 0;
  for(unsigned i = gap; i < n; i++){
    unsigned v = a[i];
    int j = i - gap;
    while(j >= 0 && a[j] > v){
      a[j+gap] = a[j];
      j -= gap;
      count++;
    }
    a[j+gap] = v;
  }
  return count;
}

void shell_sort(unsigned a[], unsigned n){
  unsigned gap_num = 0;
  while(gaps[++gap_num] < n);
  gap_num--;

  unsigned count = 0;
  for(int i=gap_num;i>=0;i--) count += insertion_sort(a,n,gaps[i]);

  std::cout << (gap_num+1) << '\n';

  for(int i=gap_num;i;i--) std::cout << gaps[i] << ' ';
  std::cout << gaps[0] << '\n';

  std::cout << count << '\n';
}

int main(){
  std::ios::sync_with_stdio(false);
  unsigned n;
  std::cin >> n;
  std::vector<unsigned> a(n);
  for(unsigned i = 0; i < n; i++) std::cin >> a[i];
  shell_sort(a.data(),n);
  for(auto &v : a) std::cout << v << '\n';
}