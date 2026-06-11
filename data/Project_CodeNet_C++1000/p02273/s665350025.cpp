#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>

using namespace std;

#define BUF_SIZE (1 << 13)

typedef struct {
  double x;
  double y;
} Point;

Point main_buf[BUF_SIZE];
Point sub_buf[BUF_SIZE];

bool is_end(const Point* point)
{
  return point->x == 100.0 && point->y == 0;
}

void copy_point(Point* dst, const Point* src)
{
  memcpy(dst, src, sizeof(*dst));
}

void rotate_60(Point* res, const Point* src)
{
  res->x = src->x * cos(M_PI / 3.0) - src->y * sin(M_PI / 3.0);
  res->y = src->x * sin(M_PI / 3.0) + src->y * cos(M_PI / 3.0);
}

void compute_rotated_point(Point* res, const Point* p1, const Point* p3)
{
  Point zero_based;
  zero_based.x = p3->x - p1->x;
  zero_based.y = p3->y - p1->y;
  rotate_60(res, &zero_based);
  res->x = res->x + p1->x;
  res->y = res->y + p1->y;
}

void split_edge(Point* dst, const Point* src_left, const Point* src_right)
{
  copy_point(&dst[0], src_left);
  dst[1].x = (src_right->x - src_left->x) / 3.0 + src_left->x;
  dst[1].y = (src_right->y - src_left->y) / 3.0 + src_left->y;
  dst[3].x = 2.0 * (src_right->x - src_left->x) / 3.0 + src_left->x;
  dst[3].y = 2.0 * (src_right->y - src_left->y) / 3.0 + src_left->y;
  copy_point(&dst[4], src_right);
  compute_rotated_point(&dst[2], &dst[1], &dst[3]);
}

void next_state()
{
  int index = 0;
  int sub_index = 0;
  while(!is_end(&main_buf[index])) {
    split_edge(&sub_buf[sub_index], &main_buf[index], &main_buf[index+1]);
    index++;
    sub_index += 4;
  }
  memcpy(main_buf, sub_buf, (sub_index+1) * sizeof(*sub_buf));
}

void print_point(const Point* point)
{
  printf("%f %f\n", point->x, point->y);
}


void print_points()
{
  int index = 0;
  while(!is_end(&main_buf[index])) {
    print_point(&main_buf[index]);
    index++;
  }
  print_point(&main_buf[index]);
}

void init_points()
{
  main_buf[0].x = 0.0;
  main_buf[0].y = 0.0;
  main_buf[1].x = 100.0;
  main_buf[1].y = 0;
}

int main()
{
  int num;
  scanf("%d", &num);
  init_points();
  for(int i = 0; i < num; i++) {
    next_state();
  }
  print_points();
  return 0;
}

